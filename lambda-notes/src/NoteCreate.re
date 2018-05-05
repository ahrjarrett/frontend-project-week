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

let component = ReasonReact.reducerComponent("NoteCreate");

let make = (~message, _children) => {
  ...component,
  initialState: () => {notes: LoremIpsum.data},
  reducer: (action, {notes}) =>
    switch (action) {
    | Add(noteContent) =>
      ReasonReact.Update({notes: [newNote(noteContent), ...notes]})
    },
  render: ({send}) =>
    <div className="App">
      <Sidebar
        message
        onView=(_e => ReasonReact.Router.push("/"))
        onCreate=(_e => ReasonReact.Router.push("/notes/create"))
      />
      <Form onSubmit=(noteContent => send(Add(noteContent))) />
    </div>,
};