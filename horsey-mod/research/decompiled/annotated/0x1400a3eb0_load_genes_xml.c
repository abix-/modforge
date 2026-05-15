// =============================================================================
// FUN_1400a3eb0 @ 0x1400a3eb0 -- proposed name: load_genes_xml
//
// PURPOSE:
//   Loads the gene table from data/genes.xml. Pre-fills a 240-entry table at
//   DAT_1403ee4a4 with default values (mutation=100, scale=1, alleles=0), then
//   parses genes.xml, looks up each gene by name in the table, and overwrites
//   the per-gene attributes (m, s, g0..g3, n) from the XML.
//
// CALLED BY: the XML data-loading initialization sequence (early in game startup).
// SIZE: 2,491 bytes (medium).
//
// KEY GLOBALS:
//   DAT_1403ee4a4   -- the gene table base. 240 entries x 32 bytes = 7,680 bytes
//                       per gene:
//                          uint32 index        @ +0x00
//                          uint32 m            @ +0x04   (mutation rate, default 100)
//                          uint64 s            @ +0x08   (scale, default 1)
//                          uint64 unknown      @ +0x10   (zero by default)
//                          uint64 unknown      @ +0x18   (zero by default)
//                       (allele values g0..g3 and codon order n are written later by
//                       the per-attribute parse; their offsets are inferred from
//                       genes.xml semantics.)
//   s_genes_xml_14030cc50 -- the literal string "genes.xml".
//
// HORSEY MOD IMPLICATION:
//   The size 240 means the gene table is HARDCODED to 240 slots. genes.xml in
//   vanilla has 241 line-defined genes (line count - <exp>/</exp> tags). Adding
//   genes beyond ~240 would not be recognized by code that indexes the table.
// =============================================================================

void load_genes_xml(void)
{
  // ... local variables ...

  // --- BEGIN INITIALIZATION OF DEFAULT GENE TABLE ---
  // Pre-fill the 240-entry gene table with sensible defaults.
  uVar25 = 0;
  uVar26 = 0;
  puVar11 = &DAT_1403ee4a4;       // pointer to gene table base
  uVar30 = uVar25;
  do {
    puVar11[-1] = (int)uVar30;    // entry.index = i
    *puVar11 = 100;               // entry.mutation_rate = 100  (matches genes.xml m="100" common case)
    *(undefined8 *)(puVar11 + 1) = 1;  // entry.scale = 1        (matches genes.xml s="1" default)
    *(undefined8 *)(puVar11 + 3) = 0;  // entry.??? = 0
    *(undefined8 *)(puVar11 + 5) = 0;  // entry.??? = 0
    uVar21 = (int)uVar30 + 1;
    uVar30 = (ulonglong)uVar21;
    puVar11 = puVar11 + 8;        // advance 8 uint32 = 32 bytes per gene entry
  } while ((int)uVar21 < 0xf0);   // 0xf0 = 240 entries
  // --- END DEFAULT INIT ---

  // Initialize the XML parser state (likely tinyxml/pugixml wrapper).
  FUN_140025e00(local_118);

  // Stage filename "genes.xml" on the stack for the parser.
  local_res10[0] = 0;
  local_198 = (undefined8 *******)0x9;       // 9 = strlen("genes.xml")
  uStack_190 = 0xf;                          // 15 = small-string-optimization capacity flag
  local_1a8 = (undefined8 ******)s_genes_xml_14030cc50._0_8_;     // bytes 0..7 of "genes.xml"
  ppppppuStack_1a0 = (undefined8 ******)(ulonglong)(byte)s_genes_xml_14030cc50[8];  // byte 8

  // Open the XML file. Returns a parse-tree root node, or 0 on failure.
  lVar12 = FUN_1400c43d0(&local_1a8, local_res10);

  if (lVar12 != 0) {
    // Hand the parse tree to the XML walker.
    FUN_1400293d0(local_118, lVar12);
    uVar13 = FUN_140025320(local_118);   // get first child element
    lVar12 = FUN_140025320(uVar13);      // get first grandchild = first <gene> tag

    // ... copy a few constants from globals into locals (perf optimization) ...

    local_res18 = lVar12;

    // Iterate over each <gene> element.
    while (lVar12 != 0) {
      // Reset name buffer.
      // local_1a8 / ppppppuStack_1a0 / local_198 / uStack_190 = empty std::string
      ppppppuStack_1a0 = (undefined8 *******)0x0;
      local_198 = (undefined8 *******)0x0;
      uStack_190 = 0xf;
      local_1a8 = (undefined8 *******)0x0;

      // Read the "name" attribute from the <gene> tag.
      // DAT_140304430 is likely the literal string "name".
      pcVar14 = (char *)FUN_1400256d0(lVar12, &DAT_140304430);

      if (pcVar14 != (char *)0x0) {
        // Copy the name into a local std::string.
        // (Standard std::string SSO/heap dance follows.)
        local_188 = (undefined8 *******)0x0;
        ppppppuStack_180 = (undefined8 *******)0x0;
        local_178 = (undefined8 *******)0x0;
        uStack_170 = 0;
        strlen(pcVar14);
        FUN_140027e30(&local_188, pcVar14);
        // ... assign local_188.. to local_1a8.. ...
        local_1a8 = local_188;
        ppppppuStack_1a0 = ppppppuStack_180;
        local_198 = local_178;
        uStack_190 = uStack_170;
      }

      // (Then: look up gene by name in the table, parse other attrs, store...)
      // (Continues for ~2KB more bytes; see all_functions.c lines 75900+ for full body.)

      // Advance to next <gene> sibling.
      // ...
    }
  }
}
