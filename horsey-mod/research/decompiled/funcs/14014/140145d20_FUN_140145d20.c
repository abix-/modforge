// Address: 0x140145d20
// Ghidra name: FUN_140145d20
// ============ 0x140145d20 FUN_140145d20 (size=309) ============


int * FUN_140145d20(longlong param_1)



{

  uint uVar1;

  char cVar2;

  int *piVar3;

  uint uVar4;

  uint uVar5;

  

  cVar2 = FUN_1401489c0();

  if (cVar2 == '\0') {

    FUN_14012e850("Parameter \'%s\' is invalid","surface");

    return (int *)0x0;

  }

  uVar1 = *(uint *)(param_1 + 4);

  uVar5 = (int)uVar1 >> 0x1c & 0xf;

  if (uVar1 == 0) {

LAB_140145dfe:

    uVar4 = uVar1 & 0xf000000;

    if (((uVar4 != 0xc000000) && (uVar4 != 0x2000000)) && (uVar4 != 0x3000000)) {

LAB_140145e16:

      FUN_14012e850("The surface is not indexed format");

      return (int *)0x0;

    }

    if ((uVar1 != 0) && (uVar5 != 1)) goto LAB_140145d83;

  }

  else {

    if (uVar5 != 1) goto LAB_140145e16;

    if ((uVar1 & 0xf000000) != 0x1000000) goto LAB_140145dfe;

  }

  uVar4 = (int)uVar1 >> 8 & 0xff;

LAB_140145d83:

  piVar3 = (int *)FUN_14017a030(1 << ((byte)uVar4 & 0x1f));

  if (piVar3 != (int *)0x0) {

    if (*piVar3 == 2) {

      **(undefined1 **)(piVar3 + 2) = 0xff;

      *(undefined1 *)(*(longlong *)(piVar3 + 2) + 1) = 0xff;

      *(undefined1 *)(*(longlong *)(piVar3 + 2) + 2) = 0xff;

      *(undefined1 *)(*(longlong *)(piVar3 + 2) + 4) = 0;

      *(undefined1 *)(*(longlong *)(piVar3 + 2) + 5) = 0;

      *(undefined1 *)(*(longlong *)(piVar3 + 2) + 6) = 0;

    }

    cVar2 = FUN_1401487f0(param_1,piVar3);

    if (cVar2 != '\0') {

      FUN_14017a0f0(piVar3);

      return piVar3;

    }

    FUN_14017a0f0(piVar3);

  }

  return (int *)0x0;

}




