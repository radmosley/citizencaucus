<template>
<div id="code">
  <navbar>
  </navbar>
  <div id="container">
  <Sidebar>
  </Sidebar>
  <Content>
  </Content>
  </div>
</div>
</template>

<script>
import Navbar from './components/Navbar.vue'
import Sidebar from './components/Sidebar.vue'
import Content from './components/Content.vue'


export default {
  name: 'app',
  components: {
    Navbar,
    Sidebar,
    Content
  }
}
</script>

<style lang="scss">
#app {
  font-family: 'Avenir', Helvetica, Arial, sans-serif;
  -webkit-font-smoothing: antialiased;
  -moz-osx-font-smoothing: grayscale;
  text-align: center;
  color: #2c3e50;
  margin-top: 60px;
}
body {
  margin:0;
  padding:0;
}

#container {
  display: flex;
}
</style>
