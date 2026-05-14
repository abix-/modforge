// Address: 0x1401631f0
// Ghidra name: FUN_1401631f0
// ============ 0x1401631f0 FUN_1401631f0 (size=111) ============


void FUN_1401631f0(void)



{

  int *piVar1;

  int *piVar2;

  int iVar3;

  

  piVar1 = (int *)FUN_140217520();

  if (piVar1 != (int *)0x0) {

    iVar3 = 0;

    if (0 < *piVar1) {

      piVar2 = piVar1 + 2;

      do {

        if (*(code **)(piVar2 + 2) != (code *)0x0) {

          (**(code **)(piVar2 + 2))(*(undefined8 *)piVar2);

        }

        iVar3 = iVar3 + 1;

        piVar2 = piVar2 + 4;

      } while (iVar3 < *piVar1);

    }

    FUN_1402175d0(0);

    FUN_1401841e0(piVar1);

    FUN_140138fb0(&DAT_1403fc340,0xffffffff);

  }

  return;

}




