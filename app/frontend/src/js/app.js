import React from 'react';
import { render } from 'react-dom';
import store from './Store';

import List from './components/List';

class App extends React.Component {
  render() {
    return <List />;
  }
}

render(
  <App />,
  document.getElementById('root')
);
