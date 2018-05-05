let toString = ReasonReact.string;

let valueFromEvent = e => (
                            e
                            |> ReactEventRe.Form.target
                            |> ReactDOMRe.domElementToObj
                          )##value;