## Actividad 3

### Daniel Estuardo Cuque Ruíz
### 202112145


### 1. Crear el archivo que contiene el script

```bash
#!/bin/bash

while true; do
    echo "Hola, la fecha actual es: $(date)"
    sleep 1
done
```

### 2. Crear un archivo de systemd unit en la ruta `/etc/systemd/system/` llamado `actividad3.service` que contenga la siguiente información:

```bash
[Unit]
Description=actividad3 y fecha infinitos

[Service]
Type=simple
ExecStart=/usr/local/bin/actividad3.sh

[Install]
WantedBy=multi-user.target
```

### 3. Habilitar el servicio

```bash
sudo systemctl daemon-reload
sudo systemctl enable actividad3.service
```

### 4. Iniciar el servicio

```bash
sudo systemctl start actividad3.service
```

### 5. Verificar el estado del servicio

Para verificar los logs del servicio se puede utilizar el comando `journalctl` con el siguiente comando:

```bash
journalctl -u actividad3.service
```

### 6. Detener el servicio

```bash
sudo systemctl stop actividad3.service
```
