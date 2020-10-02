import React from 'react';
import { Paper } from '@material-ui/core';
import { Grid } from '@material-ui/core';


export default function GridContainer(props) {

    return (

        <Grid container {...props}>
            {/* {props.children} */}
        </Grid>

    );
}
