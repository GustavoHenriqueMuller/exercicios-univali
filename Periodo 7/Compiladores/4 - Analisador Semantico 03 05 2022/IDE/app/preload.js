const { ipcRenderer, contextBridge } = require('electron');

contextBridge.exposeInMainWorld('electron', {
  dialog: (method, config) => ipcRenderer.invoke('dialog', method, config),
  childProcess: (method, ...commands) => ipcRenderer.invoke('childProcess', method, ...commands),
  fs: (method, ...commands) => ipcRenderer.invoke('fs', method, ...commands)
});
