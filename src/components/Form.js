import React, { Component, useState } from 'react';
import ReactDOM from "react-dom";

class Form extends Component {
    constructor() {
        super();

        this.state = {
            value: ""
        }
    }

    render() {
        return(
            <form>
                <input type="text" placeholder="type something"/>
            </form>
        )
    }
}

export default Form;