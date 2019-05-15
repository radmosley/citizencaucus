<template>
<div class="content">
  <ListIcon />
  <ListIcon />
  <ListIcon />
  <ListIcon />
  <ListIcon />
  <ListIcon />
  <ListIcon />
</div>
</template>

<script>
import ListIcon from './ListIcon'

export default {
  name: 'Content',
  components: {
    ListIcon
  }
}
</script>

<style>
.content {
  float: left;
  position: relative;
  display: flex;
  flex-flow: row wrap;
  justify-content: space-around;
  width: 85vw;
  margin-top: 8vh;
}
</style>