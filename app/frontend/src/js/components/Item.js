import React from 'react';
import store from './../Store';

export default class Item extends React.Component {

  
  constructor(props){
    super(props);
    this._toggleState = this._toggleState.bind(this);
  }


  _toggleState() {
    let data = {
      state: this.props.state == 'on' ? 'off' : 'on'
    };

    store.dispatch((dispatch) => {
      fetch('/devices/' + this.props.id, {
        method: 'PUT',
        body: JSON.stringify(data),
        headers: {
          'Accept': 'application/json',
          'Content-Type': 'application/json',
          'Authorization': 'Token token='+ '1234'
        }
      }).then((res) => {
        return res.json();
      }).then((res) => {
        dispatch({type: 'RECEIVE_ITEM', payload: res})
      });
    });   
  }

  render() {
    return (
      <article className="media">
        <figure className="media-left">
          <p className="image is-128x128">
            <img src="/assets/bulb.png" />
          </p>
        </figure>
        <div className="media-content">
          <div className="content">
            <p>
              <strong>{this.props.name}</strong>
              <br/>
              {this.props.ip}
              <br/>
              {this.props.pingedAt}
            </p>
            <label className="switch">
              <input type="checkbox" value="on" checked={this.props.state == 'on' ? true : false} onChange={this._toggleState}/>
              <div className="slider" />
            </label>
          </div>
        </div>
      </article>
    );
  }
}
