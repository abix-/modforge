// Address: 0x1402c8ea8
// Ghidra name: __CxxFrameHandler3
// ============ 0x1402c8ea8 __CxxFrameHandler3 (size=134) ============


/* Library Function - Single Match

    __CxxFrameHandler3

   

   Library: Visual Studio 2019 Release */



void __CxxFrameHandler3(longlong param_1,undefined8 param_2,undefined8 param_3,longlong param_4)



{

  undefined8 uVar1;

  longlong lVar2;

  undefined8 local_res8;

  

  uVar1 = *(undefined8 *)(param_4 + 8);

  local_res8 = param_2;

  lVar2 = FUN_1402c97f8();

  *(undefined8 *)(lVar2 + 0x60) = uVar1;

  uVar1 = *(undefined8 *)(param_1 + 0x38);

  lVar2 = FUN_1402c97f8();

  *(undefined8 *)(lVar2 + 0x68) = uVar1;

  lVar2 = FUN_1402c97f8();

  thunk_FUN_1402cb4e0(param_1,&local_res8,param_3,param_4,

                      (ulonglong)**(uint **)(param_4 + 0x38) + *(longlong *)(lVar2 + 0x60),0,0,0);

  return;

}




