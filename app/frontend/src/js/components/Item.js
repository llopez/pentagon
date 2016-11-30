import React from 'react';

export default class Item extends React.Component {
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
              <input type="checkbox" value="on" checked={this.props.state == 'on' ? true : false} />
              <div className="slider" />
            </label>
          </div>
        </div>
      </article>
    );
  }
}
