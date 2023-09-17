import React from 'react'

const Zad1 = () => {
    const Localdate = new Date().toLocaleDateString();
  return (
    <h3>Сегодня {Localdate}</h3>
  )
}

export default Zad1