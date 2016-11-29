import React from 'react';
import Item from './Item';
import store from './../Store';

export default class List extends React.Component {
  constructor(props){
    super(props);
    this.state = {items: []};
  }

  componentWillMount() {
    store.subscribe(() => {
      this.setState({items: store.getState()});
    });
  }

  render() {
    let items = this.state.items.map((i) => {
      return <Item key={i.id} name={i.name} ip={i.ip_address} pingedAt={i.pinged_at} />;
    });

    return (
      <div>
        {items}
      </div>
    );
  }
}
