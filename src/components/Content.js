import React, { Component } from 'react';
import GridContainer from './GridContainer';
import { Container } from '@material-ui/core';
import { Grid } from '@material-ui/core';
import Card from './Card';


/**
 * @function Content
 */
const Content = () => (
     
 <Container>
        <GridContainer spacing={5}>
            <Grid item xs={12} md={6} lg={3} xl={3}>
                <Card  />
            </Grid>
            <Grid item xs={12} md={6} lg={3} xl={3}>
                <Card    />
            </Grid>
            <Grid item xs={12} md={6} lg={3} xl={3}>
                <Card   />
            </Grid>
            <Grid item xs={12} md={6} lg={3} xl={3}>
                <Card   />
            </Grid>
            
        </GridContainer>
    </Container> 
)

 
export default Content;