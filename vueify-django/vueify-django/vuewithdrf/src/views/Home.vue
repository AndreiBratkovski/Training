<template>
  <section class="container">
    <h1> Welcome to your APP</h1>
    <redirectButton pathname="cat"></redirectButton>
  </section>
</template>
<script>
  import redirectButton from '../components/redirect'
  export default {
    components: {
      redirectButton
    }
  }
</script>
<style scoped lang="sass">

.container
    h1
      color: green
</style>