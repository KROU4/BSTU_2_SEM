import React from 'react'
import "../styles/zad2.css"

 const data = [{
        stock_name: "EFX",
        company_name: "Equifax Inc",
        price: 163.55,
        currency: "USD",
        change: "+9.03"
    }, {
        stock_name: "IRM",
        company_name: "Iron Mountain Inc",
        price: 33.21,
        currency: "USD",
        change: "+1.42"
    }, {
        stock_name: "NTAP",
        company_name: "NetApp Inc",
        price: 54.81,
        currency: "USD",
        change: "-6.01"
    }, {
        stock_name: "CTL",
        company_name: "Centurylink Inc",
        price: 13.79,
        currency: "USD",
        change: "-1.37"
    }]


    function Zad2(){
        return(
            <div>
            <table> 
                {data.map((obj)=>(
                    <tr>
                        <td>{obj.stock_name}</td>
                        <td>{obj.company_name}</td>
                        <td>{obj.price}</td>
                        <td>{obj.currency}</td>
                        <td style={{backgroundColor: (Number(obj.change) > 0 )? "#90ee90" : "#ff4c5b"}}>{obj.change}</td> 
                    </tr>
                ) )}
            </table>
            </div>
         )
    }

export default Zad2