import React from 'react';
import { render } from 'react-dom';
import { createStore } from 'redux';

import List from './components/List';

class App extends React.Component {
  render() {
    return <List />;
  }
}

const listReducer = (state = [], action) => {

  switch (action.type) {
    case 'ADD_ITEM':
      return state.concat(action.payload);
      break;
    default:
      return state;
  }
};

const store = createStore(listReducer);

store.subscribe(() => {
  console.log(store.getState());
});

render(
  <App />,
  document.getElementById('root')
);



window.store = store;
