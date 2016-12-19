import React from 'react';
import { render } from 'react-dom';
import store from './Store';
import List from './components/List';

class App extends React.Component {
  render() {
    return <List />;
  }
}


App.devices = App.cable.subscriptions.create("DevicesChannel", {
  connected: function() {},
  disconnected: function() {},
  received: function(data) {

    store.dispatch((dispatch) => {
      fetch('/api/v1/devices', {
        method: 'GET',
        headers: {
          'Accept': 'application/json',
          'Content-Type': 'application/json',
          'Authorization': 'Token token='+ '1234'
        }
      }).then((res) => {
        return res.json();
      }).then((res) => {
        dispatch({type: 'RECEIVE_ITEMS', payload: res})
      });
    });


  }
});

store.dispatch((dispatch) => {
  fetch('/api/v1/devices', {
    method: 'GET',
    headers: {
      'Accept': 'application/json',
      'Content-Type': 'application/json',
      'Authorization': 'Token token='+ '1234'
    }
  }).then((res) => {
    return res.json();
  }).then((res) => {
    dispatch({type: 'RECEIVE_ITEMS', payload: res})
  });
});

render(
  <App />,
  document.getElementById('root')
);
