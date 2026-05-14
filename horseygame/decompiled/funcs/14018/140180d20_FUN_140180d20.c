// Address: 0x140180d20
// Ghidra name: FUN_140180d20
// ============ 0x140180d20 FUN_140180d20 (size=262) ============


undefined8 FUN_140180d20(longlong *param_1,longlong *param_2)



{

  char cVar1;

  int iVar2;

  longlong lVar3;

  code *pcVar4;

  longlong *local_res8;

  undefined4 local_18;

  undefined4 local_14;

  undefined4 local_10;

  undefined4 local_c;

  

  lVar3 = FUN_1401885b0("D3D9.DLL");

  *param_1 = lVar3;

  if (lVar3 != 0) {

    cVar1 = FUN_140142940("SDL_WINDOWS_USE_D3D9EX",0);

    if (((cVar1 != '\0') &&

        (pcVar4 = (code *)FUN_140188550(*param_1,"Direct3DCreate9Ex"), pcVar4 != (code *)0x0)) &&

       (iVar2 = (*pcVar4)(0x80000020,&local_res8), -1 < iVar2)) {

      local_18 = 0x81bdcbca;

      local_14 = 0x426d64d4;

      local_10 = 0x1ad8dae;

      local_c = 0x5c27f447;

      iVar2 = (**(code **)*local_res8)(local_res8,&local_18,param_2);

      (**(code **)(*local_res8 + 0x10))();

      if (-1 < iVar2) {

        return 1;

      }

    }

    pcVar4 = (code *)FUN_140188550(*param_1,"Direct3DCreate9");

    if (pcVar4 != (code *)0x0) {

      lVar3 = (*pcVar4)(0x80000020);

      *param_2 = lVar3;

      if (lVar3 != 0) {

        return 1;

      }

    }

    FUN_140188670(*param_1);

    *param_1 = 0;

  }

  *param_2 = 0;

  return 0;

}




