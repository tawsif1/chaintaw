/** @jsx jsx */
import React from 'react'
import { css, jsx } from '@emotion/core'


const Details = ({div, divSetter}) =>
(div && (
    <div
      css={css`
        height: 475px;
        background: black;
        width: 100%;
        position: absolute;
        border: 2px solid white;
        
        z-index: 99;
        .Icon {
          font-size: 32px;
          color: white;
          position: absolute;
          right: 20px;
          top: 20px;
          cursor: pointer;
        }
      `}
    >
     <h1>hi</h1> 
    </div>)
  
)

export default Details