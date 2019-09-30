class memory_package_t {
    public:
        uint32_t processor_id;                  /// if (read / write) PROCESSOR.ID   else if (write-back / prefetch) CACHE_MEMORY.ID
        uint64_t opcode_number;                 /// initial opcode number
        uint64_t opcode_address;                /// initial opcode address
        uint64_t uop_number;                    /// initial uop number (Instruction == 0)
        uint64_t memory_address;                /// memory address
        uint32_t memory_size;                   /// operation size after offset

        package_state_t status;                  /// package state
        uint64_t readyAt;                   /// package latency
        uint64_t born_cycle;                    /// package create time

        memory_operation_t memory_operation;    /// memory operation
        memory_request_client_t* client; ///update this

        memory_package_t();
        ~memory_package_t();

        void updatePackageUntreated(uint32_t stallTime);
        void updatePackageReady(uint32_t stallTime);
        void updatePackageWait(uint32_t stallTime);
        void updatePackageFree(uint32_t stallTime);
};