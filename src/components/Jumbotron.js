/** @jsx jsx */
import React from 'react'
import { css, jsx } from '@emotion/core'
import Button from './Button.js'
import wallpaper from '../img/slide04.jpg'
import logo from '../img/whitelogo.png'


/**
 * @function Jumbotron
 */
const Jumbotron = () => (
  <div css={JumbotronCSS}>
    <div className="synopsis">
      <img src={logo} />

    <p className='info'>Find Your Dream Car</p>

     <p className='name'>CAR M5 GRAN TURISMO</p>

     <div className='car'>
     <Button icon="car">Buy</Button>
     </div>
     <div className="circle">
     <Button icon="info-circle ">More Info</Button>
     </div>
      
     

      
    </div>

    
  </div>
)

const JumbotronCSS = css`
  position: relative;
  background-image: url('${wallpaper}');
  background-repeat: no-repeat;
  background-size: cover;
  width: 100%;
  height: 98vh;
  padding-left: 60px;
  top: 0;
  .synopsis {
    padding-top: 200px;
    max-width: 700px;
    color: white;
    img {
      width: 25%;
    }
    i {
    
      margin-right: 10.5px;
    }
    div{
        padding: 05px;
         
    }
  }
  p.name {
    font: small-caps bold 40px sans serif;
  }
  p.info {
    font: italic small-caps bold 30px sans serif;
 
  }
  
  
`
export default Jumbotron