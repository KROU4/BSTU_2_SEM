import React, { Component } from 'react';
import  "../styles/style.css";

class Clock extends Component {
  constructor(props) {
    super(props);
    this.state = {
      time: new Date(),
    };
  }

  componentDidMount() {
    this.intervalID = setInterval(() => {
      this.setState({
        time: new Date(),
      });
    }, 1000);
  }

  componentWillUnmount() {
    clearInterval(this.intervalID);
  }

  formatTime = (date, format) => {
    let hours = date.getHours();
    let minutes = date.getMinutes();
    let seconds = date.getSeconds();
    let ampm = format === '12' ? (hours >= 12 ? 'pm' : 'am') : '';

    hours = format === '12' ? ((hours + 11) % 12 + 1) : hours;
    if (minutes < 10 && seconds < 10) {
      return `${hours}:${"0" + minutes}:${"0" + seconds} ${ampm}`;
    } else if (minutes < 10) {
      return `${hours}:${"0" + minutes}:${seconds} ${ampm}`;
    } else if (seconds < 10) {
      return `${hours}:${minutes}:${"0" + seconds} ${ampm}`;
    } else {
      return `${hours}:${minutes}:${seconds} ${ampm}`;
    }    
  };

  render() {
    const { format = '24', timezone = 'auto' } = this.props;
    const { time } = this.state;

    let offset = 0;
    if (timezone !== 'auto') {
      const offsetParts = timezone.split(':');
      const offsetHours = parseInt(offsetParts[0]);
      const offsetMinutes = parseInt(offsetParts[1]);
      offset = offsetHours * 60 + offsetMinutes;
    }
    const clientOffset = new Date().getTimezoneOffset(); //Получает разницу в минутах между временем на локальном компьютере и универсальным скоординированным временем (UTC).
    const localTime = time.getTime() + (clientOffset * 60 * 1000);
    const offsetTime = new Date(localTime + (offset * 60 * 1000));

    const formattedTime = this.formatTime(offsetTime, format);

    return <div id='clock'>{formattedTime}</div>;
  }
}

export default Clock;