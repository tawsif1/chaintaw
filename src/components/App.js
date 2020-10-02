import React, { useState, useEffect, createRef } from 'react'
import { Global, css, jsx } from '@emotion/core';
import Navbar from './Navbar';
import Jumbotron from './Jumbotron';
import GridContainer from './GridContainer';
import { Container } from '@material-ui/core';
import { Grid } from '@material-ui/core';
import Card from './Card';
import Details from './Details'



/**
 * @function App
 
 */

const App = () => {

 const [div,  setDiv] = useState(false)

 const divSetter =()=>{
  setDiv(prevstate => !prevstate);
  console.log('works')

 }

return(
  <>
    <Global styles={GlobalCSS} />
    <Navbar />
    <Jumbotron />
    <div style={{height:'100px'}}></div>
    <Container>
        <GridContainer spacing={5}>
            <Grid item xs={12} md={6} lg={3} xl={3}>
                <Card onClick={() => { console.log('onClick') }}/>
            </Grid>
            <Grid item xs={12} md={6} lg={3} xl={3}>
                <Card  onClick = {divSetter}  />
            </Grid>
            <Grid item xs={12} md={6} lg={3} xl={3}>
                <Card  onClick = {divSetter} />
            </Grid>
            <Grid item xs={12} md={6} lg={3} xl={3}>
                <Card  onClick = {divSetter}  />
            </Grid>
            
        </GridContainer>
    </Container> 


    <Details divSetter={divSetter} div={div} />
     

  </>
)
}

const GlobalCSS = css`
  * {
    box-sizing: border-box;
    font-family: 'Roboto', sans-serif;
  }
  html,
  body,
  .app {
    margin: 0;
    min-height: 100%;
    width: 100%;
  }
  body {
    background: #151515;
  }
  a {
    text-decoration: none;
    color: white;
  }
  p {
    font-size: 20px;
  }
  ul {
    margin: 0;
    list-style: none;
    padding: 0;
  }
  button {
    background-color: rgba(51, 51, 51, 0.8);
    border: 1px solid white;
    padding: 0.75em 2.3em;
    border-radius: 0.2vw;
    box-shadow: none;
    font-size: 1.1vw;
    color: white;
    margin-right: 15px;
    cursor: pointer;
    font-weight: 600;
    letter-spacing: 0.4px;
  }
  i {
    font-size: 18.5px;
  }
`

export default App