// Address: 0x140058030
// Ghidra name: FUN_140058030
// ============ 0x140058030 FUN_140058030 (size=356) ============


undefined8 FUN_140058030(longlong *param_1)



{

  longlong *plVar1;

  longlong lVar2;

  int iVar3;

  bool bVar4;

  longlong local_res8;

  

  FUN_1400d0a00(param_1,0);

  if (param_1[0x29] == 0) {

    local_res8 = FUN_140106bc0(DAT_1403fb0d8,(int)param_1[1]);

    if (local_res8 != 0) {

      plVar1 = (longlong *)param_1[0x27];

      if (plVar1 == (longlong *)param_1[0x28]) {

        FUN_140030680(param_1 + 0x26,plVar1,&local_res8);

      }

      else {

        *plVar1 = local_res8;

        param_1[0x27] = param_1[0x27] + 8;

      }

      FUN_1400d0a00(param_1,1);

    }

  }

  FUN_1400ce540(param_1,0,0);

  if (param_1[0x29] != 0) {

    *(undefined1 *)(param_1 + 0x4d) = 1;

    *(undefined1 *)((longlong)param_1 + 0x27c) = 1;

    *(undefined1 *)(param_1 + 0x52) = 1;

    *(undefined1 *)((longlong)param_1 + 0x2a4) = 1;

    *(undefined1 *)(param_1 + 0x57) = 1;

  }

  *(undefined8 *)((longlong)param_1 + 700) = 0;

  *(undefined2 *)((longlong)param_1 + 0x2c4) = 0x101;

  (**(code **)(*param_1 + 0x58))(param_1);

  iVar3 = *(int *)((longlong)param_1 + 0x254);

  if (iVar3 == 2) {

    iVar3 = 3;

    *(undefined4 *)((longlong)param_1 + 0x254) = 3;

  }

  else {

    bVar4 = iVar3 == 3;

    if (!bVar4) goto LAB_140058145;

  }

  if ((*(int *)((longlong)param_1 + 0x2cc) == 0) &&

     ((int)param_1[0x5a] + 4 < *(int *)(DAT_1403fb0d8 + 0x314))) {

    *(undefined4 *)((longlong)param_1 + 0x254) = 0;

    *(undefined2 *)(param_1 + 0x5b) = 0;

    *(undefined4 *)((longlong)param_1 + 0x2cc) = 1;

    iVar3 = 0;

  }

  bVar4 = iVar3 == 3;

LAB_140058145:

  *(bool *)(param_1[0xc] + 0x8e6) = !bVar4;

  *(bool *)(param_1[0xc] + 0x94e) = *(int *)((longlong)param_1 + 0x254) != 3;

  lVar2 = param_1[0xc];

  *(bool *)(lVar2 + 0x9b6) = *(int *)((longlong)param_1 + 0x254) != 3;

  *(undefined1 *)((longlong)param_1 + 0x2da) = 0;

  *(undefined4 *)(param_1 + 0x4a) = 0;

  return CONCAT71((int7)((ulonglong)lVar2 >> 8),1);

}




