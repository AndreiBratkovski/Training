<template>
  <footer>
    <p>Created by a guy who wants to stay anonymous because this app is very useless</p>
    <div id="sitemaps">
      <h5>Sitemap</h5>
      <ul>
        <router-link tag='li' :to="{ name: 'home'}">
          <a>Home</a>
        </router-link>
        <router-link tag='li' :to="{ name: 'cutecat'}">
          <a>CuteCat</a>
        </router-link>
      </ul>
    </div>
  </footer>
</template>
<script>
export default{
  data () {
    return {
}
  }
}
</script>
<style scoped lang="sass">

footer
  position: fixed
  bottom: 0
  background-color: green
  border-top: 2px solid darken(green, 20%)
  padding: 0 15px
  color: white
  ul
    padding: 0
    display: flex
    justify-content: space-around
    list-style: none
    a
      text-decoration: none
      color: white
</style>