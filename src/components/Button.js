/** @jsx jsx */
import React from 'react'
import { css, jsx } from '@emotion/core'

const Button = ({ children, type, icon }) => (
  <button type={type}>
    {icon && <i className={`fa fa-${icon}`}></i>}
    {children}
  </button>
)

Button.defaultProps = {
  type: 'button',
  icon: null
}

export default Button