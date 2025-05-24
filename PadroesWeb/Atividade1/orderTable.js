let crescente = true;

function sortTable(coluna) {
  const tabela = document.getElementById("disciplinasTable");
  const linhas = Array.from(tabela.tBodies[0].rows);

  const ehNumero = coluna === 2 || coluna === 3;

  linhas.sort((a, b) => {
    let aTexto = a.cells[coluna].innerText.trim();
    let bTexto = b.cells[coluna].innerText.trim();

    if (ehNumero) {
      aTexto = Number(aTexto);
      bTexto = Number(bTexto);
    }

    if (aTexto < bTexto) return crescente ? -1 : 1;
    if (aTexto > bTexto) return crescente ? 1 : -1;
    return 0;
  });

  crescente = !crescente;

  linhas.forEach(linha => tabela.tBodies[0].appendChild(linha));
}
