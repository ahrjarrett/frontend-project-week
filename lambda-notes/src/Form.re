open Types;

open Helpers;

type state = noteContent;

type action =
  | NewTitle(string)
  | NewBody(string);

let component = ReasonReact.reducerComponent("Form");

let make = (~onSubmit, _children) => {
  ...component,
  initialState: () => {title: "", body: ""},
  reducer: (action, state) =>
    switch (action) {
    | NewTitle(newTitle) => ReasonReact.Update({...state, title: newTitle})
    | NewBody(newBody) => ReasonReact.Update({...state, body: newBody})
    },
  render: ({state, send}) =>
    <div className="Form">
      <input
        name="title"
        value=state.title
        _type="text"
        placeholder="Note Title"
        onChange=(e => send(NewTitle(valueFromEvent(e))))
      />
      <input
        name="body"
        value=state.body
        _type="text"
        placeholder="Note Body"
        onChange=(e => send(NewBody(valueFromEvent(e))))
      />
      <input
        _type="button"
        value="Add Note"
        onClick=(_e => onSubmit({title: state.title, body: state.body}))
      />
    </div>,
};