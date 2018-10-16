<template>
  <div id="app">
    <MyHeader></MyHeader>
    <router-view></router-view>
    <MyFooter></MyFooter>
  </div>
</template>

<script>
import MyHeader from './components/Header'
import MyFooter from './components/Footer'

export default {
  components: {
    MyHeader,
    MyFooter
  },
}
</script>

<style scoped lang="sass">
html, body
  margin: 0
  min-height: 100vh
</style>
