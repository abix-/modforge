// Address: 0x14014a430
// Ghidra name: FUN_14014a430
// ============ 0x14014a430 FUN_14014a430 (size=272) ============


int * FUN_14014a430(longlong param_1,int param_2,longlong param_3)



{

  undefined8 uVar1;

  undefined8 uVar2;

  char cVar3;

  int *piVar4;

  int iVar5;

  undefined8 *puVar6;

  

  if (param_3 == 0) {

    iVar5 = *(int *)(param_1 + 0x22c);

    puVar6 = (undefined8 *)(param_1 + 0x21c);

  }

  else {

    iVar5 = *(int *)(param_3 + 0x28);

    puVar6 = (undefined8 *)(param_3 + 0x30);

  }

  if ((((param_2 == 10) || (cVar3 = FUN_14014ae60(param_1,puVar6), cVar3 != '\0')) &&

      ((*(char *)(param_1 + 0x292) != '\0' || (cVar3 = FUN_14014af50(param_1), cVar3 != '\0')))) &&

     ((*(char *)(param_1 + 0x293) != '\0' || (cVar3 = FUN_14014adb0(param_1), cVar3 != '\0')))) {

    piVar4 = (int *)FUN_1401499f0(param_1);

    if (piVar4 != (int *)0x0) {

      *piVar4 = param_2;

      piVar4[2] = 0;

      piVar4[3] = 0;

      piVar4[4] = 0;

      piVar4[5] = 0;

      piVar4[6] = *(int *)(param_1 + 0x218);

      uVar1 = *puVar6;

      uVar2 = puVar6[1];

      piVar4[0xb] = iVar5;

      *(longlong *)(piVar4 + 0xc) = param_3;

      *(undefined8 *)(piVar4 + 7) = uVar1;

      *(undefined8 *)(piVar4 + 9) = uVar2;

      if (param_3 != 0) {

        piVar4[0xe] = *(int *)(param_3 + 0x2c);

      }

      piVar4[0xf] = 1;

      piVar4[0x10] = 1;

      *(undefined8 *)(piVar4 + 0x12) = *(undefined8 *)(param_1 + 0x238);

      if (*(longlong *)(param_1 + 0x238) != 0) {

        *(undefined4 *)(*(longlong *)(param_1 + 0x238) + 8) = *(undefined4 *)(param_1 + 600);

      }

    }

  }

  else {

    piVar4 = (int *)0x0;

  }

  return piVar4;

}




