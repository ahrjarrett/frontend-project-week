[%bs.raw {|require('./App.css')|}];

open Types;

open Helpers;

let delete = (id, notes) => List.filter(n => n.id !== id, notes);

module NoteItem = {
  let component = ReasonReact.statelessComponent("NoteItem");
  let make = (~note, ~clickDelete, _children) => {
    ...component,
    render: _self => {
      let {id, content} = note;
      let {title, body} = content;
      <div
        className="noteTitle"
        onClick=(
          _e => ReasonReact.Router.push("/notes/" ++ string_of_int(id))
        )>
        <div> (toString(title)) </div>
        <hr />
        <div> (toString(body)) </div>
        <input
          _type="button"
          className="deleteNote"
          value="x"
          onClick=(_e => clickDelete())
        />
      </div>;
    },
  };
};

module Top = {
  type state = {notes: list(note)};
  type action =
    | Add(noteContent)
    | Delete(int);
  let newNote =
    (
      () => {
        let lastId = ref(-1);
        noteContent => {
          lastId := lastId^ + 1;
          {id: lastId^, content: noteContent};
        };
      }
    )();
  let component = ReasonReact.reducerComponent("App");
  let make = (~message, _children) => {
    ...component,
    initialState: () => {notes: []},
    reducer: (action, {notes}) =>
      switch (action) {
      | Add(noteContent) =>
        ReasonReact.Update({notes: [newNote(noteContent), ...notes]})
      | Delete(id) => ReasonReact.Update({notes: delete(id, notes)})
      },
    render: ({state: {notes}, send}) =>
      <div className="App">
        <Sidebar
          message
          onView=(_e => ReasonReact.Router.push("/"))
          onCreate=(_e => ReasonReact.Router.push("/notes/create"))
        />
        <Form onSubmit=(noteContent => send(Add(noteContent))) />
        <div className="NotesList">
          (
            List.map(
              note =>
                <NoteItem
                  key=(string_of_int(note.id))
                  note
                  clickDelete=(() => send(Delete(note.id)))
                />,
              notes,
            )
            |> Array.of_list
            |> ReasonReact.array
          )
        </div>
      </div>,
  };
};