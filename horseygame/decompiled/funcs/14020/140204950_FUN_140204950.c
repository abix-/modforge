// Address: 0x140204950
// Ghidra name: FUN_140204950
// ============ 0x140204950 FUN_140204950 (size=175) ============


undefined8 FUN_140204950(longlong param_1,int param_2)



{

  longlong lVar1;

  int iVar2;

  char cVar3;

  undefined8 uVar4;

  int local_res8 [2];

  

  lVar1 = *(longlong *)(param_1 + 0x2e0);

  local_res8[0] = 0;

  if (*(longlong *)(param_1 + 0x118) == 0) {

    if (param_2 != 0) {

      uVar4 = FUN_14012e850("That operation is not supported");

      return uVar4;

    }

  }

  else {

    cVar3 = FUN_140202f30(*(undefined8 *)(lVar1 + 8),*(longlong *)(param_1 + 0x118),param_2,

                          local_res8);

    iVar2 = local_res8[0];

    if (cVar3 == '\0') {

      return 0;

    }

    if (local_res8[0] != *(int *)(lVar1 + 0x74)) {

      cVar3 = FUN_140138370(*(undefined8 *)(lVar1 + 8),*(undefined8 *)(param_1 + 0x118),

                            *(undefined4 *)(lVar1 + 0x70),local_res8[0]);

      if (cVar3 == '\0') {

        return 0;

      }

      *(int *)(lVar1 + 0x74) = iVar2;

    }

  }

  return 1;

}




