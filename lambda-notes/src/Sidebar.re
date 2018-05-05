let toString = ReasonReact.string;

let component = ReasonReact.statelessComponent("Sidebar");

let make = (~message, ~onView, ~onCreate, _children) => {
  ...component,
  render: _self =>
    <div className="Sidebar">
      <h3> (toString(message)) </h3>
      <button onClick=(_e => onView())>
        (toString("View Your Notes"))
      </button>
      <button onClick=(_e => onCreate())>
        (toString("+ Create New Note"))
      </button>
    </div>,
};