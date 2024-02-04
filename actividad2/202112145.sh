#!/bin/bash

# Verificar si el comando jq está instalado
if ! [ -x "$(command -v jq)" ]; then
  echo "El comando jq no está instalado. Por favor instale jq."
  exit 1
fi

# Obtener el valor de la variable de entorno GITHUB_USER
GITHUB_USER="$GITHUB_USER"

# Verificar si la variable está definida
if [ -z "$GITHUB_USER" ]; then
  echo "La variable de entorno GITHUB_USER no está definida."
  exit 1
fi

# Construir la URL de la API de GitHub
API_URL="https://api.github.com/users/$GITHUB_USER"

# Consultar la API de GitHub y almacenar la respuesta en un archivo temporal
RESPONSE=$(curl -s "$API_URL")

# Extraer los valores del JSON
ID=$(echo "$RESPONSE" | jq -r '.id')
CREATED_AT=$(echo "$RESPONSE" | jq -r '.created_at')

# Crear el mensaje
MESSAGE="Hola $GITHUB_USER. User ID: $ID. Cuenta fue creada el: $CREATED_AT."

# Crear el directorio de logs en /tmp con el formato de fecha
LOG_DIR="/tmp/$(date +\%Y\%m\%d)"
mkdir -p "$LOG_DIR"

# Crear el archivo de log en el directorio
LOG_FILE="$LOG_DIR/saludos.log"
echo "$MESSAGE" >> "$LOG_FILE"

# Imprimir el mensaje
echo "$MESSAGE"