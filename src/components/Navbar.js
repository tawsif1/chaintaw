/** @jsx jsx */
import React, { useState, useEffect, forwardRef } from 'react'
import { css, jsx } from '@emotion/core'
import whiteLogo from '../img/whitelogo.png';


const leftLinks = ['Home', 'About', 'Woozers', 'Contact'];

/**
 * @function Navbar
 * 
 */
const Navbar = forwardRef((props, ref) => {
  const [scrolled, setScrolled] = useState(false)

  useEffect(() => {
    const handleScroll = () =>
      window.pageYOffset > 75 ? setScrolled(true) : setScrolled(false)

    const onScroll = window.addEventListener('scroll', handleScroll)

    return () => {
      window.removeEventListener('scroll', onScroll)
    }
  }, [])

  
  const [show, setShow] = useState(false);
  const notLoad = (e) => {
    e.preventDefault();
    
     setShow(prevstate => !prevstate);
    
  }



  

  return (
    <nav
      ref={ref}
      css={[
        NavbarCSS,
        scrolled
          ? css`
              background-color: rgb(20, 20, 20);
              background-image: linear-gradient(
                to bottom,
                rgba(0, 0, 0, 0.7) 10%,
                rgba(0, 0, 0, 0)
              );
            `
          : css`
              background: transparent;
            `
      ]}
    >
      <ul>
        <li>
          <a href="/">
            <img height="75" src={whiteLogo} />
          </a>
        </li>

        {leftLinks.map(link => (
          <li key={link}>
            <a href="/">{link}</a>
          </li>
        ))}
      </ul>

      
      <ul className="right">
        <li className="search">
          <input type='text' className="search-box" placeholder="Search"style={ show  ? { display:'inline-block' } : { display:'none' }}/>
          <a className="search-btn" onClick={notLoad} href="/">
            <i className="fa fa-search" aria-hidden="true"></i>
          </a>
        </li>
      </ul>

    </nav>
  )
})

const NavbarCSS = css`
  position: fixed;
  height: 68px;
  z-index: 99;
  width: 100%;
  padding: 0 25px;
  display: flex;
  align-items: center;
  justify-content: space-between;
  ul {
    display: flex;
    align-items: center;
  }
  li {
    margin-right: 20px;
  }
  a {
    font-size: 15px;
    letter-spacing: 0.5px;
    color: #e5e5e5;
  }
  a.active {
    color: white;
    font-weight: 500;
  }
  ul.right {
    .Icon {
      color: white;
      cursor: pointer;
      font-size: 22px;
    }
  }
  
 
  input.search-box {
    position: relative;
  right: 30px;
  border-styel: solid;
  transition: 1s;

    padding: 10px;
    margine: 5px;
    width: 180px;
    
  }

  li.search:active > a.search-btn{
    background: white;
  }
`

export default Navbar

