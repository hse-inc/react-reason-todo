type state = {
    isChecked: bool
  };

type action =
  | Click
  | Toggle;
  
let todoComponent = ReasonReact.reducerComponent("TodoComponent");

let make = (_children) => {
    ...todoComponent,
    initialState: () => {isChecked: false},
    reducer: (action, state) =>
      switch (action) {
      | Click => {
          Js.log(action);
          Js.log(state);
        ReasonReact.Update({...state, isChecked: !state.isChecked})
      }
      | Toggle => {
        Js.log(action);
        Js.log(state);
        ReasonReact.Update({...state, isChecked: false})
      }
      },
    render: (self) => {
      /* let message = "Clicked " ++ string_of_int(self.state.count) ++ " times(s)"; */
      <div>
        <input id="checkBox" _type="checkbox" onClick={_event => self.send(Click)} /> 
        {ReasonReact.stringToElement("Lire reason-react !")}
        /* <MyDialog
          onClick={_event => self.send(Click)}
          onSubmit={_event => self.send(Toggle)}
        />
        {ReasonReact.stringToElement(message)} */
      </div>
    }
  };