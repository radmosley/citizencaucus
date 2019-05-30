<template>
  <div class="icon">
  <ul id="SenatorsList">
    <li v-for="senator in senators">
      {{ senator.first_name }} {{ senator.last_name }}
    </li>
  </ul>
  </div>
</template>

<style>
.icon {
  width: 200px;
  height: 250px;
  background-color: grey;
  border-radius: 10px;
  display: inline-block;
}
</style>

<script>
import { mapGetters } from 'vuex'

export default {
  name: 'SenatorsList',
  computed: {
    ...mapGetters([
      'senators',
      'isLoading'
    ])
  }

}
</script>