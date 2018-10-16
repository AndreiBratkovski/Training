<template>
  <section class="container">
    <h1> Hi Guy </h1>
    <p>Welcome on another page. Where lives the cat</p>
    <img src="https://i.imgur.com/gdWIxn2.jpg" alt="cute_cat"/>
  </section>
</template>
<script>
  export default {
    data () {
      return {
      }
    }
  }
</script>
<style scoped lang="sass">

.container
    h1
      color: green
    p
      margin: 0
      color: lighten(green, 10%)
    img
      width: 100px
      height: 100px
</style>