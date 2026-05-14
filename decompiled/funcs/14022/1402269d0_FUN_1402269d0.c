// Address: 0x1402269d0
// Ghidra name: FUN_1402269d0
// ============ 0x1402269d0 FUN_1402269d0 (size=361) ============


char FUN_1402269d0(longlong param_1,longlong param_2)



{

  int iVar1;

  int iVar2;

  int iVar3;

  longlong lVar4;

  code *pcVar5;

  char cVar6;

  longlong *local_res18;

  longlong *local_res20;

  longlong *local_38;

  longlong *local_30;

  

  cVar6 = '\0';

  lVar4 = FUN_1401885b0("dxgi.dll");

  if (lVar4 != 0) {

    pcVar5 = (code *)FUN_140188550(lVar4,"CreateDXGIFactory1");

    if ((pcVar5 != (code *)0x0) && (iVar1 = (*pcVar5)(&DAT_140356c10,&local_30), -1 < iVar1)) {

      iVar1 = 0;

      do {

        iVar2 = (**(code **)(*local_30 + 0x60))(local_30,iVar1,&local_38);

        if (iVar2 < 0) break;

        iVar2 = 0;

        while ((cVar6 == '\0' &&

               (iVar3 = (**(code **)(*local_38 + 0x38))(local_38,iVar2,&local_res20), -1 < iVar3)))

        {

          iVar3 = (**(code **)*local_res20)(local_res20,&DAT_140356c20,&local_res18);

          if (-1 < iVar3) {

            iVar3 = (**(code **)(*local_res18 + 0xd8))(local_res18,param_2);

            if ((-1 < iVar3) && (*(longlong *)(param_2 + 0x58) == param_1)) {

              cVar6 = '\x01';

            }

            (**(code **)(*local_res18 + 0x10))();

          }

          (**(code **)(*local_res20 + 0x10))();

          iVar2 = iVar2 + 1;

        }

        (**(code **)(*local_38 + 0x10))();

        iVar1 = iVar1 + 1;

      } while (cVar6 == '\0');

      (**(code **)(*local_30 + 0x10))();

    }

    FUN_140188670(lVar4);

  }

  return cVar6;

}




