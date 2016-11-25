import React from 'react';
import Item from './Item';

export default class List extends React.Component {
  render() {
    return (
      <div>
        <Item name="Lamp #1" ip="10.0.0.2" pingedAt="3 sec ago" />
      </div>
    );
  }
}
