// Address: 0x14012f4a0
// Ghidra name: _strrev
// ============ 0x14012f4a0 _strrev (size=5) ============


char * __cdecl _strrev(char *_Str)



{

  char cVar1;

  char *pcVar2;

  char *pcVar3;

  

  pcVar3 = _Str;

  do {

    pcVar2 = pcVar3;

    pcVar3 = pcVar2 + 1;

  } while (*pcVar2 != '\0');

  pcVar2 = pcVar2 + -1;

  pcVar3 = _Str;

  if (_Str < pcVar2) {

    do {

      cVar1 = *pcVar3;

      *pcVar3 = *pcVar2;

      pcVar3 = pcVar3 + 1;

      *pcVar2 = cVar1;

      pcVar2 = pcVar2 + -1;

    } while (pcVar3 < pcVar2);

  }

  return _Str;

}




