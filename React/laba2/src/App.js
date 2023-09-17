import React from 'react';
import Clock from './components/Clock';
import JobMenu from './components/JobMenu';
import  "./styles/style.css";

function App() {
  return (
    <div className='div'>
      <h1>Задание №1</h1>
      <h1 id='minsk'>Minsk Time</h1>
      <Clock format='24' timezone='+3:00' />
      <h1 id='ny'>New York Time</h1>
      <Clock format='12' timezone='-4:00' /> 
      <h1 id='num2'>Задание №2</h1>
      <JobMenu />
    </div>
  );
}

export default App;