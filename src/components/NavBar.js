import React from 'react'
import Link from 'next/link'

export default () => (
  <div className="nav-items">
    <Link href="/about-me"><a>about-me</a></Link>
    <Link href="/articles"><a>articles</a></Link>
    <Link href="/talks-projects"><a>talks-and-projects</a></Link>
    <Link href="/musts"><a>musts</a></Link>
  </div>
)
