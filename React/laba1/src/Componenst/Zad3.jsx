import React from 'react';
import '../styles/Chessboard.css';

function Chessboard(){
    
    const numbers = ["1","2","3","4","5","6","7","8"] // массив с числами от 1го до 8ми
    const evenRow = numbers.map((num,i) => (<td key={i} style={{background: (i++)%2==0? "white" : "black"}} className = "boba"></td>)) // если номер строки делится на 2 без остатка, то цвет ячейки будет белый
    const ovenRow = numbers.map((num,i) => (<td key={i} style={{background: (i++)%2==0? "black" : "white"}}></td>)) // в противном случае будет чёрный
    return(
      <div className='boba'>
         <>
        {numbers.reverse().map((num, i)=> (
            <tr  key = {i}>
                <td>
                    {num}
                </td>
               {(i++)%2==0 ? evenRow : ovenRow}
                <td>
                    {num}
                </td>

            </tr>
        ))}
        </>
      </div>
     
    )
}
  
export default Chessboard;