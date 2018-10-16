<template>
  <header>
    <div id="logo">UA</div>
    <nav>
      <ul>
        <router-link tag='li' :to="{ name: 'home'}">
          <a>Home</a>
        </router-link>
        <router-link tag='li' :to="{ name: 'cat'}">
          <a>CuteCat</a>
        </router-link>
      </ul>
    </nav>
  </header>
</template>

<script>
export default{
  data () {
    return {}
  }
}
</script>

<style scoped lang="sass">
  
header
    display: flex
    justify-content: space-around
    align-items: center
    background-color: green
    border-bottom: 2px solid darken(green, 30%)
    color: white
    div#logo
      font-size: 200%
      width: 33%
    nav
      flex-grow: 2
      ul
        padding: 0
        display: flex
        justify-content: space-around
        list-style: none
        a
          text-decoration: none
          color: white
</style>