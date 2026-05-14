// Address: 0x1401df920
// Ghidra name: FUN_1401df920
// ============ 0x1401df920 FUN_1401df920 (size=323) ============


void FUN_1401df920(longlong param_1,uint *param_2)



{

  undefined1 *puVar1;

  longlong lVar2;

  uint uVar3;

  

  puVar1 = *(undefined1 **)(param_2 + 0x4e);

  lVar2 = *(longlong *)(param_1 + 0x2e0);

  if (puVar1 != (undefined1 *)0x0) {

    if (puVar1[0x48] != '\0') {

      uVar3 = *param_2;

      if ((uVar3 == 0) || ((uVar3 & 0xf0000000) == 0x10000000)) {

        uVar3 = uVar3 & 0xff;

      }

      else if ((((uVar3 == 0x32595559) || (uVar3 == 0x59565955)) || (uVar3 == 0x55595659)) ||

              (uVar3 == 0x30313050)) {

        uVar3 = 2;

      }

      else {

        uVar3 = 1;

      }

      FUN_1401dfb70(param_1,param_2,puVar1 + 0xac,

                    (longlong)(*(int *)(puVar1 + 0xa8) * *(int *)(puVar1 + 0xb0)) +

                    (longlong)(int)(uVar3 * *(int *)(puVar1 + 0xac)) + *(longlong *)(puVar1 + 0xa0),

                    *(int *)(puVar1 + 0xa8));

      return;

    }

    (**(code **)(**(longlong **)(puVar1 + 0x20) + 0xa0))(*(longlong **)(puVar1 + 0x20),0);

    *puVar1 = 1;

    if (*(uint **)(lVar2 + 0x160) == param_2) {

      *(undefined8 *)(lVar2 + 0x160) = 0;

      *(undefined4 *)(lVar2 + 0x184) = 0;

      *(undefined8 *)(lVar2 + 0x188) = 0;

      *(undefined1 *)(lVar2 + 400) = 0;

      (**(code **)(**(longlong **)(lVar2 + 0x10) + 0x358))(*(longlong **)(lVar2 + 0x10),0);

      (**(code **)(**(longlong **)(lVar2 + 0x10) + 0x208))(*(longlong **)(lVar2 + 0x10),0,0);

    }

  }

  return;

}




