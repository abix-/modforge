// Address: 0x14017d3c0
// Ghidra name: FUN_14017d3c0
// ============ 0x14017d3c0 FUN_14017d3c0 (size=143) ============


int FUN_14017d3c0(uint param_1,int param_2)



{

  uint uVar1;

  int iVar2;

  

  if (param_2 - 1U < 0xc) {

    iVar2 = *(int *)(&DAT_140336f7c + (longlong)param_2 * 4);

    if (param_2 == 2) {

      uVar1 = param_1 & 0x80000003;

      if ((int)uVar1 < 0) {

        uVar1 = (uVar1 - 1 | 0xfffffffc) + 1;

      }

      if ((uVar1 == 0) &&

         ((param_1 != ((int)param_1 / 100) * 100 || (param_1 == ((int)param_1 / 400) * 400)))) {

        iVar2 = iVar2 + 1;

      }

    }

    return iVar2;

  }

  FUN_14012e850("Month out of range [1-12], requested: %i");

  return -1;

}




