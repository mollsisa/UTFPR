const formulario = document.getElementById("formularioMusical");
const estilos = document.querySelectorAll('input[name="estilos"]');
const containerArtistas = document.getElementById("containerArtistas");
const erroEstilos = document.getElementById("erroEstilos");

function atualizarArtistas() {
  containerArtistas.innerHTML = "";
  estilos.forEach((estilo) => {
    if (estilo.checked) {
      const div = document.createElement("div");
      div.className = "grupo-artistas";
      div.innerHTML = `
        <label>Artistas de ${estilo.value}</label>
        <textarea name="artistas_${estilo.value.toLowerCase()}" rows="2" required placeholder="Digite os artistas separados por vírgula"></textarea>
        <span class="erro"></span>
      `;
      containerArtistas.appendChild(div);
    }
  });
}

estilos.forEach((estilo) =>
  estilo.addEventListener("change", atualizarArtistas)
);

formulario.addEventListener("submit", (e) => {
  e.preventDefault();
  let valido = true;

  formulario
    .querySelectorAll("input[required], select[required], textarea[required]")
    .forEach((campo) => {
      const erro = campo.nextElementSibling;
      const valor = campo.value.trim();

      if (!valor) {
        erro.textContent = "Campo obrigatório";
        valido = false;
      } else if (campo.type === "email" && !campo.validity.valid) {
        erro.textContent = "E-mail inválido";
        valido = false;
      } else if (
        campo.name === "telefone" &&
        !/^\(\d{2}\) \d{4,5}-\d{4}$/.test(valor)
      ) {
        erro.textContent = "Telefone inválido";
        valido = false;
      } else {
        erro.textContent = "";
      }
    });

  if (![...estilos].some((c) => c.checked)) {
    erroEstilos.textContent = "Selecione pelo menos um estilo musical";
    valido = false;
  } else {
    erroEstilos.textContent = "";
  }

  if (valido) {
    alert("Formulário enviado com sucesso!");
    formulario.reset();
    containerArtistas.innerHTML = "";
  }
});
