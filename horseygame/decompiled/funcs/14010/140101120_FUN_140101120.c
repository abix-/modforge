// Address: 0x140101120
// Ghidra name: FUN_140101120
// ============ 0x140101120 FUN_140101120 (size=239) ============


void FUN_140101120(longlong param_1,int param_2,int param_3,undefined4 param_4)



{

  int iVar1;

  int *piVar2;

  undefined8 *puVar3;

  int *piVar4;

  int iVar5;

  ulonglong uVar6;

  int local_18;

  undefined4 uStack_14;

  

  if ((((-1 < param_2) && (iVar1 = *(int *)(param_1 + 0x278), param_2 < iVar1)) && (-1 < param_3))

     && (param_3 < *(int *)(param_1 + 0x27c))) {

    piVar2 = *(int **)(param_1 + 0x420);

    iVar5 = 0;

    puVar3 = *(undefined8 **)(param_1 + 0x428);

    uVar6 = (longlong)puVar3 - (longlong)piVar2 >> 3;

    if (uVar6 != 0) {

      piVar4 = piVar2;

      do {

        if (*piVar4 == iVar1 * param_3 + param_2) {

          if (piVar2[(longlong)iVar5 * 2 + 1] != -1) {

            return;

          }

          break;

        }

        iVar5 = iVar5 + 1;

        piVar4 = piVar4 + 2;

      } while ((ulonglong)(longlong)iVar5 < uVar6);

    }

    local_18 = iVar1 * param_3 + param_2;

    if (puVar3 == *(undefined8 **)(param_1 + 0x430)) {

      uStack_14 = param_4;

      FUN_140030680((undefined8 *)(param_1 + 0x420),puVar3,&local_18);

    }

    else {

      *puVar3 = CONCAT44(param_4,local_18);

      *(longlong *)(param_1 + 0x428) = *(longlong *)(param_1 + 0x428) + 8;

    }

  }

  return;

}




