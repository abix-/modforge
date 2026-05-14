// Address: 0x14007ac40
// Ghidra name: FUN_14007ac40
// ============ 0x14007ac40 FUN_14007ac40 (size=202) ============


void FUN_14007ac40(undefined8 *param_1,char *param_2,longlong param_3)



{

  undefined4 uVar1;

  char cVar2;

  undefined1 *puVar3;

  undefined8 uVar4;

  undefined1 local_res10 [8];

  undefined1 local_res20;

  undefined1 local_res21;

  undefined1 local_18;

  undefined1 local_17;

  undefined1 local_16;

  undefined1 local_15;

  

  cVar2 = *param_2;

  if (cVar2 != '\0') {

    param_3 = param_3 + -8;

    do {

      param_2 = param_2 + 1;

      if (cVar2 != ' ') {

        if (cVar2 == '1') {

          local_res10[0] = *(undefined1 *)(param_3 + 8);

          puVar3 = local_res10;

          uVar4 = 1;

        }

        else if (cVar2 == '2') {

          puVar3 = &local_res20;

          local_res20 = (undefined1)*(undefined4 *)(param_3 + 8);

          uVar4 = 2;

          local_res21 = (undefined1)((uint)*(undefined4 *)(param_3 + 8) >> 8);

        }

        else {

          if (cVar2 != '4') {

            return;

          }

          uVar1 = *(undefined4 *)(param_3 + 8);

          puVar3 = &local_18;

          local_18 = (undefined1)uVar1;

          uVar4 = 4;

          local_17 = (undefined1)((uint)uVar1 >> 8);

          local_15 = (undefined1)((uint)uVar1 >> 0x18);

          local_16 = (undefined1)((uint)uVar1 >> 0x10);

        }

        param_3 = param_3 + 8;

        (*(code *)*param_1)(param_1[1],puVar3,uVar4);

      }

      cVar2 = *param_2;

    } while (cVar2 != '\0');

  }

  return;

}




