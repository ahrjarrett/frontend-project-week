open Types;

open Helpers;

type state = {notes: list(note)};

type action =
  | Add(noteContent);

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

module NoteItem = {
  let component = ReasonReact.statelessComponent("NoteItem");
  let make = (~note, _children) => {
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
      </div>;
    },
  };
};

let component = ReasonReact.reducerComponent("App");

let make = (~message, _children) => {
  ...component,
  initialState: () => {notes: LoremIpsum.data},
  reducer: (action, {notes}) =>
    switch (action) {
    | Add(noteContent) =>
      ReasonReact.Update({notes: [newNote(noteContent), ...notes]})
    },
  render: ({state: {notes}}) =>
    <div className="App">
      <Sidebar
        message
        onView=(_e => ReasonReact.Router.push("/"))
        onCreate=(_e => ReasonReact.Router.push("/notes/create"))
      />
      <div className="NotesList">
        (
          List.map(
            note => <NoteItem key=(string_of_int(note.id)) note />,
            notes,
          )
          |> Array.of_list
          |> ReasonReact.array
        )
      </div>
    </div>,
};