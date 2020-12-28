const button = document.getElementById('button');
const div_number = document.getElementById('number');

button.addEventListener('click', () => {
	div_number.innerText = '';
	fetch('http://localhost:3000/number')
		.then((res) => res.json())
		.then((data) => div_number.innerText = data.number)
		.catch((err) => console.log(err));
});
